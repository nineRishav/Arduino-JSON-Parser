# JSON parser for Arduino : No External Library

Serial Data Parsing is recommended(Baud-rate)
Can’t store more than 256 characters in the Buffer Memory. So I have to Extract and store only required variables

![JSON Parser](https://i.ytimg.com/vi/WmoGFs6IQVs/maxresdefault.jpg)

### Input :
![JSON Parser](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2017/08/open-weather-map-test-api.png?resize=813.75%2C309&ssl=1)

##### Open Weather API Data

----------------
### Approach

1. Stored only alpha-characters, colon,& comma for further parsing
2. Using colon for parsing and separating the values
3. Then Applying Search Algorithm to find the only the required keywords

---

### Output
`coord:lon:75.9,lat:22.72,weather:id:800,main:Clear,description:clearsky,icon:01d,base:stations,main:temp:36.91,pressure:952.84,humidity:32,temp_min:36.91,temp_max:36.91,sea_level:1009.45,grnd_level:952.84,wind:speed:7.96,deg:268.509,clouds:all:0,dt:1528890123,sys:message:0.01,country:IN,sunrise:1528848664,sunset:1528897322,id:1269743,name:Indore,cod:200`

Converts Json into key-value Pair.
e.g. **temp,pressure,humidity and wind-speed** can be easily extracted, stored in buffer memory and others can be ignored

### **Application Areas**
- Space Compact programs
- No Use of External Library
