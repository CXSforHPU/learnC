import os

target_md = "./注意的题.md"
picture_path = "./picture"

if __name__ == "__main__":

    picture_names = os.listdir(picture_path)
    with open(target_md, "w",encoding="utf8") as f:
        for picture_name in picture_names:
            if picture_name.split(".")[0] == "1":
                f.write("# {}\n".format("第二章"))
            f.write("![]({})\n".format(os.path.join(picture_path, picture_name)))
