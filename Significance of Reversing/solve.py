# Mở tệp đầu vào (file gốc) và tệp đầu ra (tệp tái tạo)
input_filename = "Reverseme.png"  # Tên tệp nguồn
output_filename = "reversed_file.LEF"  # Tên tệp tái tạo

with open(input_filename, 'rb') as infile:
    # Đọc toàn bộ nội dung tệp và đảo ngược dữ liệu
    data = infile.read()

# Đảo ngược dữ liệu byte
reversed_data = data[::-1]

# Ghi dữ liệu đảo ngược vào tệp đầu ra
with open(output_filename, 'wb') as outfile:
    outfile.write(reversed_data)

print(f"File đã được đảo ngược và lưu vào {output_filename}")
