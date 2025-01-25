import json


def json_to_markdown(json_data):
    headers = ["Problem No.", "Title", "Solution", "Tags", "Submission ID"]
    markdown_table = "| " + " | ".join(headers) + " |\n"
    markdown_table += (
        "| " + " | ".join(["-" * len(header) for header in headers]) + " |\n"
    )

    for entry in json_data:
        prob_no = entry["prob_no"]
        prob_title = entry["prob_title"]
        prob_link = entry["prob_link"]
        vol = entry["link_vol"]
        sol_link = f"UVA/Volume_{vol}/UVA{prob_no}.cpp"
        tags = entry["tags"] if entry["tags"] else ""
        tags = " ".join([f"`{tag}`" for tag in tags.split()])
        sub_id = entry["sub_id"]

        row = [
            f"[{prob_no}]({prob_link})",
            prob_title,
            f"[UVA{prob_no}.cpp]({sol_link})",
            tags,
            sub_id,
        ]
        markdown_table += "| " + " | ".join(row) + " |\n"
    return markdown_table

if __name__ == "__main__":
    with open("summary.json") as summary:
        table = json_to_markdown(json.load(summary))
    with open("README.template.md") as template:
        template = template.read()
    with open("README.md", "w") as readme_file:
        readme_file.write(template.replace("SUMMARY_TABLE", table))
