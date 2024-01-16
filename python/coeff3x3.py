from variables import *
from converter import text_to_array
from save import *

Weights = {
    "conv1" : [],
    "conv2" : [],
    "conv3" : [],
    "local3": []
}

Biases = {
    "conv1" : [],
    "conv2" : [],
    "conv3" : [],
    "local3": []
}

# Parcourir tous les fichiers dans le dossier
def get_weights_and_biases(dir_path='cnn_coeff_3x3'):
    print("Getting weights and the biases.")
    dossier_path = dir_path
    for fichier_nom in os.listdir(dossier_path):
        fichier_path = os.path.join(dossier_path, fichier_nom)

        # Appliquer la fonction text_to_array pour obtenir la matrice
        matrice_resultante = text_to_array(fichier_path)

        # Identifier le type (weights ou biases) et la couche à partir du nom du fichier
        if "weights" in fichier_nom:
            type_parametre = Weights
        elif "biases" in fichier_nom:
            type_parametre = Biases
        else:
            continue  # Ignorer les fichiers qui ne sont ni des poids ni des biais

        # Identifier la couche à partir du nom du fichier

        if "conv1" in fichier_nom:
            matrice = (np.array(matrice_resultante)).T
            type_parametre["conv1"]  = matrice
        elif "conv2" in fichier_nom:
            matrice = (np.array(matrice_resultante)).T
            type_parametre["conv2"]  = matrice
        elif "conv3" in fichier_nom:
            matrice = (np.array(matrice_resultante)).T
            type_parametre["conv3"]  = matrice
        elif "local3" in fichier_nom:
            matrice = (np.array(matrice_resultante)).T
            type_parametre["local3"] = matrice
    
    # Appliquer la fonction save_weights_to_txt à chaque élément des dictionnaires
    for layer_type, layer_dict in [("weights", Weights)]:
        for layer_name, layer_matrix in layer_dict.items():
            if not isinstance(layer_matrix, np.ndarray):
                continue  # Ignore les éléments vides

            # Spécifier le nom du fichier de sortie
            output_file = f"save/weights_biases/{layer_name}_{layer_type}.txt"

            # Appeler la fonction pour sauvegarder les poids dans le fichier .txt
            save_weights_for_cpp(layer_matrix, output_file)
    save_weights_to_text(Weights)
