import base64

# Giải mã password
anionic_password = "NjQzMzcyNzUzNTM3MzE2Njc5MzE2ZTM2"
decoded_hex = base64.b64decode(anionic_password).decode('ascii')
password = bytes.fromhex(decoded_hex).decode('ascii')

# Thông tin đăng nhập
username = "AdminFeroxide"
ALKALINE_SECRET = "4143454354467B34707072336E373163335F3634322C28010D3461302C392E"

# Chuyển đổi sang hex
hex_username = username.encode().hex()
hex_password = password.encode().hex()

# Tính toán các giá trị nguyên lớn
username_int = int(hex_username, 16)
password_int = int(hex_password, 16)
covalent_link = username_int ^ password_int
alkaline_secret_int = int(ALKALINE_SECRET, 16)
metallic_alloy = covalent_link ^ alkaline_secret_int

# Xử lý hex và giải mã flag
precipitate = hex(metallic_alloy)[2:]
if len(precipitate) % 2 != 0:
    precipitate = '0' + precipitate

alloy_bytes = bytes.fromhex(precipitate)
flag = alloy_bytes.decode('ascii')

print(f"Flag: {flag}")