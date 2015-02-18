def sum_numbers_in_file(filename):
    """
    Return the sum of the numbers in the given file (which only contains
    integers separated by whitespace).
    >>> sum_numbers_in_file("numb.txt")
    19138
    """
    f = open(filename, 'r+')
    m = f.readlines()
    n = sum([sum([int(x) for x in line.split()]) for line in m])
    f.close()
    return n
print sum_numbers_in_file("tmpok")
