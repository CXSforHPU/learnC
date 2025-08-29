import os
import shutil

include_original_path = "../include"
src_original_path = "../src"

include_target_path = "./include"
src_target_path = "./src"

def copy_file(original_path, target_path):
    file_names = os.listdir(original_path)
    for file_name in file_names:
        original_file_path = os.path.join(original_path, file_name)
        target_file_path = os.path.join(target_path, file_name)
        if os.path.isdir(original_file_path):
            os.makedirs(target_file_path, exist_ok=True)  # 添加exist_ok=True避免错误
            copy_file(original_file_path, target_file_path)
        
        if os.path.isfile(original_file_path):
            try:
                # 以UTF-8编码读取文件
                with open(original_file_path, "r", encoding="utf-8") as f:
                    content = f.read()
                
                # 以ANSI编码写入文件
                with open(target_file_path, "w", encoding="ansi",errors="ignore") as f:

                    # 处理内容替换
                    if file_name == "main.c":
                        new_content = content.replace("CP_UTF8", "936")
                    else:
                        new_content = content
                        
                    f.write(new_content)
                    
                print("copy {} to {}".format(original_file_path, target_file_path))
            except UnicodeEncodeError:
                # 如果ANSI编码不支持某些字符，回退到二进制复制
                shutil.copy2(original_file_path, target_file_path)
                print("binary copy {} to {}".format(original_file_path, target_file_path))
            except Exception as e:
                print("Error copying {}: {}".format(original_file_path, str(e)))

if __name__ == "__main__":
    copy_file(include_original_path, include_target_path)
    copy_file(src_original_path, src_target_path)