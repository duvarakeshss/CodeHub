import threading
import copy

lock = threading.Lock()

def rowSort(matrix):
    with lock:
        for i in range(len(matrix)):
            if i % 2 == 0:
                matrix[i].sort()
            else:
                matrix[i].sort(reverse=True)

def colSort(matrix):
    
    with lock:
        for j in range(len(matrix[0])):
            col = [matrix[i][j] for i in range(len(matrix))]
            col.sort()
            for i in range(len(matrix)):
                matrix[i][j] = col[i]

def main():
    
    matrix = [[45, 7, 9, 35],
            [12, 85, 16, 3],
            [40, 20, 72, 88],
            [55, 78, 69, 77]]

    print(f"original matrix: {matrix}")
    
    while True:

        prev = copy.deepcopy(matrix)
        row_thread = threading.Thread(target=rowSort, args=(matrix,))
        col_thread = threading.Thread(target=colSort, args=(matrix,))

        row_thread.start()
        row_thread.join()

        col_thread.start()
        col_thread.join()
        
        print(f"matrix after sort: {matrix}")
        
        if prev == matrix:
            print("Matrix stabilized.")
            break

    
if __name__ == "__main__":
    main()