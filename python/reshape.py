def reshape(image):
    """
    The reshape function of the image before passing in the Perceptron

    Parameters
    ----------
    image : tuple (label, array)
        image.array has a shape of (n, x, y) = (number of kernels, width, height).

    Returns
    -------
    An array of shape (n*x*y,).

    """
    label, array = image
    n, x, y = array.shape
    array_reshaped = array.transpose(1, 2, 0).reshape((x * y * n,))
    return (label, array_reshaped)
