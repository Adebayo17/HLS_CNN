from variables import *

class PerceptronLayer:
    def __init__(self, input_size, num_kernels):
        """
        Perceptron Layer of a CNN architecture

        Parameters
        ----------
        input_size : TYPE
            DESCRIPTION.
        num_kernels : int
            number of kernels = numbers of image classes .

        Returns
        -------
        None.

        """
        self.num_kernels = num_kernels
        self.input_size = input_size
        
        self.weights = np.random.randn(num_kernels, input_size)
        self.biases = np.zeros((num_kernels, ))
        self.output = np.zeros((num_kernels,))
        
    ################################################################################################################

    def _softmax(self, input):
        assert input is not None
        assert len(input) != 0

        m = np.max(input)
        sum_exp = np.sum(np.exp(input - m))
        input = np.exp(input - m - np.log(sum_exp))
        
        return input
    
    ################################################################################################################

    def _apply_perceptron(self, input_data):
        """
        Apply perceptron operation to the input_data

        Parameters
        ----------
        input_data : typle (lable, array of size (input_size,))
            array of the image after reshape and his label.

        Returns
        -------
        A tuple (lable, array of size (num_kernels)).

        """
        label, image = input_data
        for k in range (self.num_kernels):
            self.output[k] = np.dot(self.weights[k, :], image) + self.biases[k]
        
        #soft = self._softmax(self.output)
        soft = self.output
        return label, soft
    
    ################################################################################################################
