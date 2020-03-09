# CS251A Advanced Computer Architecture - Winter 2020 at UCLA

The benchmark for this project is a simple 3-layer Neural Network for digit recognition. The benchmark is based on previous work completed on the following repo: https://mmlind.github.io/Simple_3-Layer_Neural_Network_for_MNIST_Handwriting_Recognition/.

### Compile and run source code

The repository comes with a pre-configured `makefile`. You can compile the source simply by typing

```
$ make
```

in the project directory. The binary will be created inside the `/bin` folder and can be executed via

```
$ ./bin/mnist-3lnn
```

### Documentation

The  `/doc` folder contains a doxygen configuration file. 
When you run it with doxygen it will create updated [HTML documentation](https://rawgit.com/mmlind/mnist-3lnn/master/doc/html/index.html) in the `/doc/html` folder.


### MNIST Database

The `/data` folder contains the original MNIST database files.

