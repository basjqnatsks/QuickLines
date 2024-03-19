from time import time

t = time()
with open('million.txt', 'rb') as f:
    for i,k in enumerate(f):
        pass
end_t = time() - t
print('Million')
print('Second: ' + str(end_t))
print(i)

t = time()
with open('billion.txt', 'rb') as f:
    for i,k in enumerate(f):
        pass
end_t = time() - t
print('Billion')
print('Second: ' + str(end_t))
print(i)
