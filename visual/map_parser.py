filepath = 'ex.txt'
with open(filepath) as fp:
    line = fp.readline()
    cnt = 1
    while line:
        print("Line {}: {}".format(cnt, line))
        line = fp.readline()
        cnt += 1

# def get_ants(num):
#     pass
#
# def get_links(room1, room2):
#     pass
#
# def get_coordinates(x, y):
#     pass
