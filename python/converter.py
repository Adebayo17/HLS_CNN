from variables import *

################################################################################################################

def read_cifar10_bin_file(file_path):
    with open(file_path, 'rb') as file:
        data = file.read()

    image_size = 3073
    num_images = len(data) // image_size
    images = []

    for i in range(num_images):
        start = i * image_size
        label, *pixels = struct.unpack("B" + "B" * (image_size - 1), data[start:start + image_size])
        images.append((label, pixels))

    return images

################################################################################################################

def text_to_array(file_path):
    with open(file_path, 'r') as fichier:
        # Lecture du contenu du fichier
        contenu_fichier = fichier.read()

    try:
        # Utilisation de eval pour évaluer la chaîne et la convertir en une matrice NumPy
        matrice = np.array(eval(contenu_fichier), dtype=float)
        return matrice
    except Exception as e:
        print(f"Erreur lors de la lecture de la matrice : {e}")
        return None


################################################################################################################

# Exemple d'utilisation
def test_converter():
    chemin = 'cnn_coeff_3x3\conv1_weights.txt'
    matrice_resultante = text_to_array(chemin)
    
    if matrice_resultante is not None:
        print("Matrice lue avec succès :")
        print(matrice_resultante)
