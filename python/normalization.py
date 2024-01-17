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


def rgb_to_gray_and_save(input_matrix, output_filename):
    # Assurez-vous que la forme de la matrice d'entrée est correcte
    if input_matrix.shape != (3, 24, 24):
        raise ValueError("La forme de la matrice d'entrée doit être (3, 32, 32)")

    # Transposez la matrice pour obtenir l'ordre correct des dimensions
    matrix_rgb = np.transpose(input_matrix, (1, 2, 0))

    # Convertir la matrice RGB en niveaux de gris
    matrix_gray = np.dot(matrix_rgb[..., :3], [0.2989, 0.587, 0.114])

    matrix_gray_uint8 = matrix_gray.astype(np.uint8)

    # Aplatir la matrice en un tableau 1D
    flat_array = matrix_gray_uint8.reshape(-1)

    # Convertir le tableau en une chaîne de caractères avec des délimitations
    output_string = '{' + ', '.join(map(str, flat_array)) + '}'

    # Sauvegarder la chaîne dans un fichier texte
    with open(output_filename, 'w') as file:
        file.write(output_string)

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
        if( i < 10):
            rgb_to_gray_and_save(centered_image,f"save/original/image_{i}.txt")
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
