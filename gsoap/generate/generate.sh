wsdl2h lacuisine.wsdl service.wsdl
mkdir serviceHost
soapcpp2 -S -L -w -x -i -d./serviceHost/ lacuisine.h
rm lacuisine.h
wsdl2h lacuisine.wsdl common.xsd
mkdir clientHost
soapcpp2 -C -w -x -i -d./clientHost/ lacuisine.h
rm lacuisine.h
cp ./serviceHost/* ../
cp ./clientHost/* ../
rm -R ./serviceHost ./clientHost