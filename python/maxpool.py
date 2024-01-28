from variables import *

class MaxpoolLayer:
    def __init__(self, pool_size, window_size):
        self.pool_size = pool_size
        self.window_size = window_size

    def maxpool(self, input_image):
        label, tab_in = input_image
        input_shape = np.shape(tab_in)
        output_shape = (input_shape[0], input_shape[1] // self.pool_size, input_shape[2] // self.pool_size)

        tab_out = np.zeros(output_shape)

        for i in range(input_shape[0]):
            for j in range(0, input_shape[1], self.pool_size):
                for k in range(0, input_shape[2], self.pool_size):
                    # Adjust the window boundaries to stay within the image
                    window_start_j = min(j, input_shape[1] - self.window_size)
                    window_start_k = min(k, input_shape[2] - self.window_size)
                    window = tab_in[i, window_start_j:window_start_j + self.window_size, window_start_k:window_start_k + self.window_size]
                    tab_out[i, j // self.pool_size, k // self.pool_size] = np.max(window)

        return label, tab_out 