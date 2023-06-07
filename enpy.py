file_path = "./test1_sample.txt"

try:
    with open(file_path, "r") as file:
        for line in file:
            print(line.strip())  # 줄 바꿈 문자 제거 후 출력

except FileNotFoundError:
    print("파일을 찾을 수 없습니다.")
