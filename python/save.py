from variables import *
from normalization import *

################################################################################################################

def save_images_to_binary_file(images, file_path):
    print("Saving image in the binary format (.bin file)\n")
    with open(file_path, 'wb') as file:
        for label, normalized_image in images:
            # Convert label to byte
            label_byte = struct.pack('B', label)
            
            # Convert normalized image data to 16-bit integer (2 bytes per pixel)
            image_data_bytes = normalized_image.astype(np.int16).tobytes()

            # Write label byte and image data bytes to the file
            file.write(label_byte + image_data_bytes)

#save_images_to_binary_file(get_images(), 'images_normalized.bin')
#save_images_to_binary_file(get_images_no_normalized(), 'images_normalized.bin')

################################################################################################################

def save_centered_image_to_text_file(img_number, file_path):
    print(f"Save image_{img_number} no normalized in {file_path} (.txt file)\n")
    test_images = get_images_no_normalized()

    # Extract the image data from the specified image number
    image_data = test_images[img_number][1]

    # Save the centered image to a text file
    with open(file_path, 'w') as file:
        for channel in image_data:
            for row in channel:
                # Write each row of the matrix to the file
                #file.write(' '.join(map(str, row)) + '\n')
                # Write each pixel value on a separate line
                file.write('\n'.join(map(str, row)) + '\n')

#img_number_to_save = 0
#save_centered_image_to_text_file(img_number_to_save, 'img_0.txt')
                
################################################################################################################

def save_weights_to_text(Weights, output_dir='save/output_weights'):
    print(f"Saving {Weights} in a text file (.txt file)\n")
    os.makedirs(output_dir, exist_ok=True)  # Créer le dossier de sortie s'il n'existe pas

    for layer, weights_matrix in Weights.items():
        if not np.any(weights_matrix):  # Ignorer les matrices vides
            continue

        # Créer le chemin du fichier de sortie
        #print(weights_matrix.shape)
        output_path = os.path.join(output_dir, f"{layer}_weights.txt")

        # Enregistrer la matrice dans un fichier texte sans la déformer
        with open(output_path, 'w') as file:
            if len(weights_matrix.shape) == 4:  # Vérifier si la matrice est 4D
                transposed_weights = weights_matrix
                transposed_weights = np.transpose(transposed_weights, (0, 1, 3, 2))
                #print(transposed_weights.shape)
                file.write("{")
                for i in range(transposed_weights.shape[0]):
                    file.write("{")
                    for j in range(transposed_weights.shape[1]):
                        file.write("{")
                        for k in range(transposed_weights.shape[2]):
                            file.write("{")
                            for l in range(transposed_weights.shape[3]):
                                file.write(str(transposed_weights[i, j, k, l]))
                                if l < transposed_weights.shape[3] - 1:
                                    file.write(", ")
                            file.write("}")
                            if k < transposed_weights.shape[2] - 1:
                                file.write(",\n ")
                        file.write("}")
                        if j < transposed_weights.shape[1] - 1:
                            file.write(",\n\n ")
                    file.write("}")
                    if i < transposed_weights.shape[0] - 1:
                        file.write(",\n\n ")
                file.write("}\n")
            elif len(weights_matrix.shape) == 2:  # Vérifier si la matrice est 2D
                transposed_weights = weights_matrix
                #print(transposed_weights.shape)
                file.write("{")
                for i in range(transposed_weights.shape[0]):
                    file.write("{")
                    for j in range(transposed_weights.shape[1]):
                        file.write(str(transposed_weights[i, j]))
                        if j < transposed_weights.shape[1] - 1:
                            file.write(", ")
                    file.write("}")
                    if i < transposed_weights.shape[0] - 1:
                        file.write(",\n ")
                file.write("}\n")
            else:
                # Gérer d'autres types de matrices si nécessaire
                pass

################################################################################################################

def save_weights_for_cpp(weights_matrix, output_file):
    # Get the shape of the weights matrix
    shape = weights_matrix.shape

    # Transpose the weights matrix to align pixels of each channel of each kernel
    # The transpose order is (0, 1, 3, 2) based on the dimensions (height, width, input_channels, output_channels)
    if(len(shape) == 4):
        transposed_matrix = np.transpose(weights_matrix, (0, 1, 3, 2))
    else:
        transposed_matrix = weights_matrix
    
    # Reshape the transposed weights matrix
    reshaped_weights = transposed_matrix.reshape(-1)

    # Format the weights list with curly braces and commas
    formatted_weights = "{" + ", ".join(map(str, reshaped_weights)) + "}"

    # Save the formatted weights string to a text file
    with open(output_file, 'w') as file:
        file.write(formatted_weights)

################################################################################################################

def save_to_hpp(data, num_images, filename):
    if num_images > len(data):
        print("Le nombre d'images demandé est supérieur à la taille du tableau. Utilisation de toutes les images disponibles.")
        num_images = len(data)

    # Tableau pour stocker les labels
    image_labels = np.array([item[0] for item in data[:num_images]], dtype=int)
    
    # Tableaux pour stocker les images
    image_arrays = [item[1].reshape(-1) for _, item in enumerate(data[:num_images])]
    
    # Enregistrement dans un fichier hpp
    with open(filename, 'w') as file:
        # Enregistrement du tableau de labels
        file.write('static double image_labels[] = {' + ', '.join(map(str, image_labels)) + '};\n\n')
        
        # Enregistrement des tableaux d'images
        for i, image_array in enumerate(image_arrays):
            file.write(f'static double image_{i}[] = {{' + ', '.join(map(str, image_array)) + '}};\n')
            file.write('\n') 
        
        # Enregistrement du tableau d'images normalisées à la fin
        file.write(f'static double* image_normalized_array[] = {{')
        file.write(', '.join([f'image_{i}' for i in range(num_images)]))
        file.write('};\n')

################################################################################################################

def rgb_to_gray_and_save(input_matrix, output_filename):
    # Assurez-vous que la forme de la matrice d'entrée est correcte
    if input_matrix.shape != (3, 24, 24):
        raise ValueError("La forme de la matrice d'entrée doit être (3, 24, 24)")

    # Transposez la matrice pour obtenir l'ordre correct des dimensions
    matrix_rgb = np.transpose(input_matrix, (1, 2, 0))

    # Convertir la matrice RGB en niveaux de gris
    matrix_gray = np.dot(matrix_rgb[..., :3], [0.2989, 0.587, 0.114])

    # Appliquer le reshape(-1) pour aplatir la matrice en un tableau 1D
    flat_array = matrix_gray.reshape(-1)

    # Sauvegarder le tableau dans un fichier texte
    np.savetxt(output_filename, flat_array, fmt='%d')

# Exemple d'utilisation de la fonction avec une matrice d'exemple et un nom de fichier de sortie
#example_matrix = np.random.randint(0, 256, size=(3, 24, 24), dtype=np.uint8)
#rgb_to_gray_and_save(example_matrix, 'output.txt')