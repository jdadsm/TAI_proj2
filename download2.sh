if [ ! -d "rawData" ]; then
    wget -O rawData.zip "https://uapt33090-my.sharepoint.com/:u:/g/personal/jmourao_ua_pt/EQH4qYfHsddNlrRYrMh_y6ABfNjl09a_0tgvqWI7uBkmtg?e=oAak78&download=1"
    unzip rawData.zip
    rm rawData.zip
else
    echo "Folder already exists. Skipping download and extraction."
fi