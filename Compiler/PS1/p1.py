from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
import time

# Set up Chrome options to ignore SSL certificate errors
chrome_options = Options()
chrome_options.add_argument('--ignore-certificate-errors')
chrome_options.add_argument('--incognito')  # Optional: Incognito mode
chrome_options.add_argument('--headless')   # Optional: Run in headless mode (no GUI)

# Initialize the WebDriver
driver = webdriver.Chrome(options=chrome_options)

# URL to scrape
url = "https://www.psgtech.edu"  # Replace with the target URL

# Navigate to the URL
driver.get(url)

# Wait for the page to load (you can increase the time if necessary)
time.sleep(5)

# Print the page's HTML
html_content = driver.page_source
with open('college.html' , 'w') as file:
    file.write(html_content)

# Optionally, close the browser once done
driver.quit()
