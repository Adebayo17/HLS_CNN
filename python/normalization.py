from variables import *

################################################################################################################
################################################################################################################

image_size = 3073 
num_images = 10000
channel_size = 24 * 24
num_channels = 3

with open('cifar-10-batches-bin/test_batch.bin', 'rb') as file:
    data = file.read()

################################################################################################################
################################################################################################################

def center_image(image):
    red_channel = image[:1024].reshape(32, 32)
    green_channel = image[1024:2048].reshape(32, 32)
    blue_channel = image[2048:].reshape(32, 32)
    image = np.dstack((red_channel, green_channel, blue_channel))
    cropped_image = image[4:28, 4:28, :]

    red_matrix = cropped_image[:, :, 0].reshape(1, 24, 24)
    green_matrix = cropped_image[:, :, 1].reshape(1, 24, 24)
    blue_matrix = cropped_image[:, :, 2].reshape(1, 24, 24)

    image_matrix = np.vstack((red_matrix, green_matrix, blue_matrix))

    return image_matrix

def normalize_image(image):
    mean = np.mean(image)
    std_dev = np.std(image)
    normalized_image = (image - mean) / np.maximum(std_dev, (1/np.sqrt(image.size)))
    # Clamp values to be within [-1, 1]
    normalized_image = np.clip(normalized_image, -1, 1)
    return normalized_image


################################################################################################################
################################################################################################################

def get_images():
    images = []
    for i in range(num_images):
        start = i * image_size
        image = np.frombuffer(data[start:start + image_size], dtype=np.uint8)
        label = image[0] 
        pixel_data = image[1:] 
        centered_image = center_image(pixel_data)
        images.append((label, normalize_image(centered_image)))
    return images

def get_images_no_normalized():
    images = []
    for i in range(num_images):
        start = i * image_size
        image = np.frombuffer(data[start:start + image_size], dtype=np.uint8)
        label = image[0] 
        pixel_data = image[1:] 
        centered_image = center_image(pixel_data)
        images.append((label, centered_image))
    return images

################################################################################################################
################################################################################################################
