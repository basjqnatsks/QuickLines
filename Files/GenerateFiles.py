TMP = ''
with open('million.txt', 'w') as f:
    for x in range(1000000):
        TMP += "test123\n"
    f.write(TMP)


# TMP = ''
# #note this requires a decent chunk of ram 
# with open('billion.txt', 'w') as f:
#     for x in range(1000000000):
#         TMP += "test123\n"
#     f.write(TMP)


TMP = ''
with open('billion.txt', 'w') as f:
    for x in range(1000000000):

        f.write("test123\n")

