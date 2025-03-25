M = []

for i in range(100,1000):
    # On subdivise chaque chiffre du nombre 
    mot = str(i)
    L = (int(k) for k in mot)
    #########################

    # On calcule la somme et le produit des chiffres 
    sum = 0         # Neutre du +
    prod = 1        # Neutre du *
    
    for k in L:
        if k != 0:  # Car la consigne n'aurait aucun sens, aucun nombre n'est divisible par 0 hormis lui-meme
            sum += k
            prod = prod * k
    ################################################

    # On vérifie si le nombre en question est divisible par la somme et le produit de ses chiffres 
    if i%sum == 0 and i%prod == 0:
        M.append(i)
        print(sum, prod)
    ##############################
# Fin de la boucle
# A la fin de la boucle, M sera remplie des éléments qui remplissent les conditions

print(M)

# On prend le minimum et le maximum

print(min(M), max(M))