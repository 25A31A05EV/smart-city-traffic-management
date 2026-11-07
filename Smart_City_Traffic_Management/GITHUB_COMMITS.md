# GitHub setup and commit guide

Run these commands from the project root after extracting the ZIP.

```bash
git init
git add README.md src/main.cpp
git commit -m "Day 1: Implement weighted road graph and Dijkstra route finder"

git add web/index.html
git commit -m "Day 2: Add interactive traffic management web prototype"

git add docs/flowchart.mmd tests/test_cases.md
git commit -m "Day 3: Add algorithm flowchart and test cases"

git add docs/Project_Report.docx
git commit -m "Day 4: Add detailed ADS project report"

git add docs/Project_Presentation.pptx
git commit -m "Day 5: Add project presentation"

git branch -M main
git remote add origin https://github.com/<YOUR-USERNAME>/smart-city-traffic-management.git
git push -u origin main
```

Before committing, compile and test the C++ code. Do not claim a commit or push succeeded until Git confirms it.
