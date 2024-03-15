def find_indices(seq, val):
    counter = 0
    result = []
    for n in seq:
        if n == val:
            result.append(counter)
        counter += 1
    return result

seq = [1, 2, 4, 2, 1]
val = 2
print(find_indices(seq, val))  # prints: [1, 3]