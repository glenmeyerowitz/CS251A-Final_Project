# CS251A Advanced Computer Architecture - Winter 2020 at UCLA

The benchmark for this project is a simple 3-layer Neural Network for digit recognition. The benchmark is based on previous work completed on the following repo: https://mmlind.github.io/Simple_3-Layer_Neural_Network_for_MNIST_Handwriting_Recognition/.

### Compile and run source code

The repository comes with a pre-configured `makefile`. You can compile the source simply by typing

```
$ make
```

in the project directory. The binary will be created inside the main directory and can be executed. In order to run the training script, use the following:

```
$ ./mnist-train
```

In order to run the test script, which should only be done after training is complete, use the following:

```
$ ./mnist-test
```

### Weight values

The file `network.dat` holds the weight values for the different nodes in the Neural Network. The size of the network can be changed by altering the `train.c` and `test.c` files. There will be tens of thousands of node values, depending on the network parameters.

### Documentation

The  `/doc` folder contains a doxygen configuration file. 
When you run it with doxygen it will create updated [HTML documentation](https://rawgit.com/mmlind/mnist-3lnn/master/doc/html/index.html) in the `/doc/html` folder.

### MNIST Database

The `/data` folder contains the original MNIST database files.

### Evaluating the network on gem5

Once the network training has been completed, it is possible to test the network on the gem5 simulator. This will allow for variations of microarchitecture parameters to see how that impacts overall performance.
