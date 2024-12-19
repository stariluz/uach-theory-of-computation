def automaton():
    states = [
        [2, 1, 4],  # 0
        [1, 1, 4],  # 1
        [2, 3, 4],  # 2
        [2, 3, 4],  # 3
        [4, 4, 4],  # 4
    ]
    finals = [1, 3]
    # states = [
    #     [0, 1, 3],  # 0
    #     [0, 2, 3],  # 1
    #     [2, 2, 3],  # 2
    #     [3, 3, 3],  # 3
    # ]
    # finals = [2]
    alphabet = ['a', 'b']
    state = 0
    result = []
    
    while True:
        c = input_file.read(1)
        if not c or c == '\n':
            break
        result.append(c)
        column = choose_column(
            len(alphabet), alphabet, c
        )
        state = states[state][column]

    return is_final(
        len(finals), finals, state
    ), ''.join(result)

def choose_column(alphabet_length, alphabet, c):
    for i in range(alphabet_length):
        if alphabet[i] == c:
            return i
    return alphabet_length

def is_final(finals_length, finals, state):
    return state in finals

# Código principal
if __name__ == '__main__':
    input_file = open(0)  # stdin en Python
    while True:
        valid, result = automaton()
        if result == '':
            break
        if valid:
            print(f"Cadena válida {result}")
        else:
            print("Cadena inválida")
