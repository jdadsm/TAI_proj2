if [ ! -d "rawData" ]; then
    wget -O rawData.zip "https://uapt33090-my.sharepoint.com/:u:/g/personal/jmourao_ua_pt/EV3KkPrPwRBGhf8_773o4jsBUoaVbI5qWTygXRSewX0COA?e=R372G1&download=1"
    unzip rawData.zip
    rm rawData.zip
else
    echo "Files already exist. Skipping download and extraction."
fi