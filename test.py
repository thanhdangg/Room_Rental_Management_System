import hashlib

def sha256_encode(input_string):
    sha256_hash = hashlib.sha256()
    
    sha256_hash.update(input_string.encode('utf-8'))
    
    return sha256_hash.hexdigest()

input_string = "TramTran2012"
encoded_string = sha256_encode(input_string)
print(f"gốc: {input_string}")
print(f"Mã hóa SHA-256: {encoded_string}")
