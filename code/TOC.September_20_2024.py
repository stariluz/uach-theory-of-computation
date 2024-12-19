import re

def regex():
    regex = re.compile(r"^(a|b)*(bb)(a|b)*$") 
    # regex = re.compile(r"(^b(a|b)*$)|(^(a|b)*b$)")

    result = input_file.readline().strip()

    valid = bool(regex.search(result))   
    return valid, result

if __name__ == "__main__":
    input_file = open(0)
    while True:
        valid, result = regex()
        if result == "":
            break
        if valid:
            print(f"Cadena válida {result}")
        else:
            print("Cadena inválida")
