import numpy as np
import time

def multiply(A, B, C):
    N = A.shape[0]
    for i in range(N):
        for j in range(N):
            C[i][j] = 0
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]

def split(matrix):
    row, col = matrix.shape
    row2, col2 = row // 2, col // 2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]

def strassen(A, B):
    if A.shape[0] == 1:
        return A * B

    a, b, c, d = split(A)
    e, f, g, h = split(B)

    p1 = strassen(a, f - h)
    p2 = strassen(a + b, h)
    p3 = strassen(c + d, e)
    p4 = strassen(d, g - e)
    p5 = strassen(a + d, e + h)
    p6 = strassen(b - d, g + h)
    p7 = strassen(a - c, e + f)

    c11 = p5 + p4 - p2 + p6
    c12 = p1 + p2
    c21 = p3 + p4
    c22 = p1 + p5 - p3 - p7

    top = np.hstack((c11, c12))
    bottom = np.hstack((c21, c22))
    c = np.vstack((top, bottom))

    return c

def Pruebas(N):
    A = np.random.randint(0, 10, size=(N, N))
    B = np.random.randint(0, 10, size=(N, N))
    C_normal = np.zeros((N, N), dtype=int)
    C_strassen = np.zeros((N, N), dtype=int)
    C_opt = np.zeros((N, N), dtype=int)

    # Multiplicación normal
    start_time = time.time() * 1000
    multiply(A, B, C_normal)
    end_time = time.time() * 1000
    print(f"Tiempo de ejecución de la multiplicación normal: {end_time - start_time:.6f} ms")

    # Multiplicación Strassen
    start_time = time.time() * 1000
    C_strassen = strassen(A, B)
    end_time = time.time() * 1000
    print(f"Tiempo de ejecución del algoritmo de Strassen: {end_time - start_time:.6f} ms")

    B_T = B.transpose()

    # Multiplicación Optimizada
    start_time = time.time() * 1000
    multiply(A, B_T, C_opt)
    end_time = time.time() * 1000
    print(f"Tiempo de ejecución del algoritmo optimizado: {end_time - start_time:.6f} ms")

# Cambiar el tamaño de las matrices a multiplicar
N = 1024
i = 2

while i <= N:
    print("i = " + str(i))
    Pruebas(i)
    i *= 2 