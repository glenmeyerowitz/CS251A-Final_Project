/**
 * @file main.c
 *
 * @mainpage MNIST 3-Layer Neural Network
 *
 * @brief Simple feed-forward neural network with 3 layers of nodes (input, hidden, output)
 * using Sigmoid or Tanh activation function and back propagation to classify MNIST handwritten digit images.
 *
 * @details Simple feed-forward neural network with 3 layers of nodes (input, hidden, output)
 * using Sigmoid or Tanh activation function and back propagation to classify MNIST handwritten digit images.
 *
 * @see [Simple 3-Layer Neural Network for MNIST Handwriting Recognition](http://mmlind.github.io/Simple_3-Layer_Neural_Network_for_MNIST_Handwriting_Recognition/)
 * @see http://yann.lecun.com/exdb/mnist/
 * @version [Github Project Page](http://github.com/mmlind/mnist-3lnn/)
 * @author [Matt Lind](http://mmlind.github.io)
 * @date August 2015
 *
 */ 

#include <stdlib.h>
#include <time.h>

#include "util/screen.h"
#include "util/mnist-utils.h"
#include "util/mnist-stats.h"
#include "3lnn.h"

/**
 *  * @brief Returns a Vector holding the image pixels of a given MNIST image
 *   * @param img A pointer to a MNIST image
 *    */

Vector *getVectorFromImage(MNIST_Image *img){

    Vector *v = (Vector*)malloc(sizeof(Vector) + (MNIST_IMG_WIDTH*MNIST_IMG_HEIGHT * sizeof(double)));

    v->size = MNIST_IMG_WIDTH*MNIST_IMG_HEIGHT;

    int i;
    for (i=0;i<v->size;i++)
        v->vals[i] = img->pixel[i] ? 1 : 0;

    return v;
}

/**
 * @brief Testing the trained network by processing the MNIST testing set WITHOUT updating weights
 * @param nn A pointer to the NN
 */

void testNetwork(Network *nn){
   
    int NUM_TEST_IMAGES = 100;
 
    // open MNIST files
    FILE *imageFile, *labelFile;
    imageFile = openMNISTImageFile(MNIST_TESTING_SET_IMAGE_FILE_NAME);
    labelFile = openMNISTLabelFile(MNIST_TESTING_SET_LABEL_FILE_NAME);
    
    int errCount = 0;
    
    // Loop through all images in the file
    int imgCount;
    for (imgCount=0; imgCount<NUM_TEST_IMAGES; imgCount++){
        
        // Reading next image and its corresponding label
        MNIST_Image img = getImage(imageFile);
        MNIST_Label lbl = getLabel(labelFile);
        
        // Convert the MNIST image to a standardized vector format and feed into the network
        Vector *inpVector = getVectorFromImage(&img);
        feedInput(nn, inpVector);
        
        // Feed forward all layers (from input to hidden to output) calculating all nodes' output
        feedForwardNetwork(nn);
        
        // Classify image by choosing output cell with highest output
        int classification = getNetworkClassification(nn);
        if (classification!=lbl) errCount++;
        
        // Display progress during testing
        displayTestingProgress(imgCount, errCount, 5,5);
//        displayImage(&img, lbl, classification, 7,6);
        
    }
    
    // Close files
    fclose(imageFile);
    fclose(labelFile);
    
}

/**
 * @details Main function to run MNIST-1LNN
 */

int main(int argc, const char * argv[]) {
    
    int hidCount = 20;
    int outCount = 10;

    // remember the time in order to calculate processing time at the end
    time_t startTime = time(NULL);
    
    // clear screen of terminal window
    printf("    MNIST-3LNN: a simple 3-layer neural network processing the MNIST handwritten digit images\n\n");
    
    // Create neural network using a manually allocated memory space
    Network *nn = createNetwork(MNIST_IMG_HEIGHT*MNIST_IMG_WIDTH, hidCount, outCount);
    loadNetworkWeights(nn);

    // Testing the during training derived network using the TESTING dataset
    testNetwork(nn);

    // Free the manually allocated memory for this network
    free(nn);

    // Calculate and print the program's total execution time
    time_t endTime = time(NULL);
    double executionTime = difftime(endTime, startTime);
    printf("\n    DONE! Total test time: %.1f sec\n\n",executionTime);

    return 0;
}
