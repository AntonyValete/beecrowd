prod = int(input())
cri = int(input())

if cri > prod:
    resp = cri - prod;
    print("Ainda faltam %d presentes!" % resp)
    
else:
    resp = prod % cri;
    print("Sobraram %d presentes!" % resp)