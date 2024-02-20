path=getwd()
path
setwd("C:/Users/Arindam/Desktop/Toll_Plaza_Record_System_by_Arindam")
traffic = read.table(file="C:/Users/Arindam/Desktop/Toll_Plaza_Record_System_by_Arindam/traffic.txt",sep="|")
names(traffic)=c("Vehicleid","Name","Date","Model","Wheels","Fair")
traffic
