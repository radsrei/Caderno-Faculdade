 M = [
    [-0.1296, -1.0623, -2.1474, -4.3135, 2.0326, 2.4264, 1.7796, -3.8439, -4.6384], 
    [-0.2717, 4.3736, 0.9403, 0.6312, -3.2139, -4.123, 0.0307, -0.026, -3.9802], 
    [-3.7343, 1.4466, 2.8519, -4.8549, -3.8834, 2.3903, -2.9121, -1.957, -0.7625], 
    [-4.58, 1.2535, 2.0439, 3.1463, -4.4391, 3.4849, -3.3579, 1.5291, 4.1022], 
    [-2.755, 3.6882, -4.6622, -4.4898, 4.7884, -3.8165, 0.5292, -4.3052, 1.344], 
    [-2.3389, -4.451, -3.5988, -2.7418, -2.0095, -0.2042, 3.2434, -4.0002, 4.7817], 
    [1.3732, -1.353, 0.967, -3.5496, -0.2692, -2.9397, 4.6731, -0.7952, -0.5834], 
    [2.4366, 1.0477, 3.5779, 3.5061, -4.114, 1.2104, 2.9883, -1.0138, 3.2923]
]

n = 8
for j in range(n-1):
    for p in range (j,n):
        if M[p][j] !=0:
            if p != j:
                M[p], M[j] = M[j],M[p]

        else:
            print('Matriz M não tem solução')



import numpy as np

def buscar_pivo(L):
    if (np.nonzero(L)[0]).size == 0:
        return -1
    else:
        return np.nonzero(L)[1][0]

def encontrar_pivos_indices(mat):
    pivos = []
    for i in range(5):
        pivos.append(buscar_pivo(np.array(mat[i])))
    return pivos

mat = np.matrix([[0,5,2,7,8],[8,10,4,14,16],[0,0,0,0,0],[2,6,10,16,22],[3,5,8,9,15]]).astype(float)
print("Matriz original:\n",mat,"\n")

pivos_indices = encontrar_pivos_indices(mat)

linha_aux = 0
for i in range(5):
    linha_aux = linha_aux + 1
    if pivos_indices[i] == -1 and linha_aux < 5 and i < 5:
        m = mat.tolist()
        (m[i],m[linha_aux]) = (m[linha_aux],m[i])
        mat = np.matrix(m)
        pivos_indices = encontrar_pivos_indices(mat)

print(mat,"\n")

linha_aux = 0
for i in range(5): 
    linha_aux = linha_aux + 1
    if pivos_indices[i] > pivos_indices[linha_aux] and linha_aux < 5 and i < 5:
        m = mat.tolist()
        (m[i],m[linha_aux]) = (m[linha_aux],m[i])
        mat = np.matrix(m)
        pivos_indices = encontrar_pivos_indices(mat)

print(mat)