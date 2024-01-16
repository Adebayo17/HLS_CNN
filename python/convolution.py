import numpy as np
from variables import *


class ConvolutionalLayer:
    def __init__(self, num_kernels, kernel_size, num_channels, output_size, activation_function='relu'):
        """
        Initializes a convolution layer with biases.

        Parameters
        ----------
        num_kernels : Int 
            Numbers of kernels in the layer.
        kernel_size : Int
            Kernel size (square side).
        activation_function : string
            The activation function of the convolutional layer.

        Returns
        -------
        None.

        """
        self.num_kernels = num_kernels
        self.kernel_size = kernel_size
        self.num_channels = num_channels
        self.activation_function = activation_function
        self.output_size = output_size
        self.output = np.zeros((self.num_kernels, self.output_size[0], self.output_size[1]))
        
        # initialize the weights and biases
        self.weights = np.ones((num_kernels, num_channels, kernel_size, kernel_size,))
        self.biases = np.zeros((num_kernels,))
    
    def _apply_activation(self, x):
        if self.activation_function == 'relu':
            return np.maximum(0, x)
        else:
            return x
        
    def _convolution_padding(self, image):
        """
        Function that performs the Convolution and relu
        Output_size <= image_size

        Parameters
        ----------
        image : array
            array of shape (c, x, y)
            c = number of channels
            x = height
            y = width.

        Returns
        -------
        tuple (label, array)
            feature maps in an array of shape (num_kernels, x, y).

        """
        label = image[0]
        img = image[1]
        _, height, width = img.shape
        output_height = self.output_size[0]
        output_width = self.output_size[1]
        
        # Calculate padding needed on each side
        pad_height = max((height - output_height + self.kernel_size - 1) // 2, 0)
        pad_width = max((width - output_width + self.kernel_size - 1) // 2, 0)

        # Pad the image
        padded_image = np.pad(img, ((0, 0), (pad_height, pad_height), (pad_width, pad_width)), mode='constant')

        weights_temp = np.transpose(self.weights, (0, 1, 3, 2))
        
        for k in range(self.num_kernels):
            for i in range(output_height):
                for j in range(output_width):
                    # Sum over all channels
                    window = padded_image[:, i:i + self.kernel_size, j:j + self.kernel_size]
                    kernel_k = weights_temp[k]
                    self.output[k, i, j] = np.sum(window * kernel_k) + self.biases[k]

        
        return (label, self._apply_activation(self.output))
    

