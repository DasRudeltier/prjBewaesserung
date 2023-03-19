#include <Arduino.h>
const char html[] PROGMEM = R"=====(<!DOCTYPE html>
<html lang="de">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, height=device-height, initial-scale=1">
<title>Bewässerungssystem - JaMaTi</title>

<style type="text/css">
body {text-align:center;font-family: Verdana; font-size: 1.2rem; color: white; background-color: black}
h3 {text-align:center;font-family: Verdana; font-size: 1.0rem; color: silver; background-color: black}
h2 {font-weight: bold; font-family: Verdana; font-size: 1.2rem; color: white; background-color: black}
h1 {font-weight: bold; font-family: Verdana; font-size: 1.6rem; color: white; background-color: black}
button{border:0;border-radius:0.3rem;background:#ffe800;color:#000000;line-height:2.0rem;font-size:1.2rem;width:20%;-webkit-transition-duration:0.4s;transition-duration:0.4s;cursor:pointer;}
button:hover{background:#ffff00;}
</style>

<script language="JavaScript">
'use strict'                
var ip = location.host;
var connection = null; 

// Setup EventListener 
document.addEventListener('DOMContentLoaded', function() {
  /*const bu_on = document.querySelector("#BU_ON");
  const bu_off = document.querySelector("#BU_OFF");
  const bu_toggle = document.querySelector("#BU_TOGGLE");

  bu_on.addEventListener("click", function () {
    sendLED1('on');
  });

  bu_off.addEventListener("click", function () {
    sendLED1('off');
  });
  
  bu_toggle.addEventListener("click", function () {
    sendLED1('toggle');
  });*/

  start();
  setInterval(check, 1000);

  });

// Setup WebSocket connection
function start(){
  if (connection != null)
    connection = null;;
  connection=new WebSocket("ws://"+ip+":81");
  //connection=new WebSocket("ws://192.168.2.111:81");
  
  connection.onopen = function(){
    connection.send('Message from Browser to ESP32 yay its Working!! ' + new Date()); 
    connection.send('ping');
    console.log('Websocket opened!');
  };
  
  connection.onerror = function(error){
    console.log('WebSocket Error ', error);
  };
  
  connection.onclose = function(){
    console.log('Websocket closed!');   
    //check();//reconnect now
  };
  
  connection.onmessage = function(e){
    if (connection.readyState === 1) {   //Verbindung wurde hergestellt      
      var jsObj = JSON.parse(e.data);
      if (jsObj.action == "response") {
        document.getElementById("TEMP").innerHTML = jsObj.TEMP; 
        document.getElementById("LUFE").innerHTML = jsObj.LUFE; 
        document.getElementById("ERFE").innerHTML = jsObj.ERFE; 
        document.getElementById("HELI").innerHTML = jsObj.HELI; 
        document.getElementById("PUMP").innerHTML = jsObj.PUMP; 
        document.getElementById("LICH").innerHTML = jsObj.LICH; 
        document.getElementById("LUER").innerHTML = jsObj.LUER; 
      }
      else { 
        console.log('Server: ', e.data);  //Daten des Websocket ausgeben, wenn kein json Objekt mit "response"
      }
    }
  };
}

// Check WebSocket connection
function check(){
  document.getElementById("READY_STATE").innerHTML = connection.readyState;
  if(!connection || connection.readyState == 3) 
    start();
}

// Send new LED1 state to server
function sendLED1(Value)
{
  if (connection == null){
    window.alert("Keine verbindung"); 
    return;
  }

  // Construct a msg object containing the data the server needs to process the message from the client.
  var msg = { };
  msg.actiona = "request";
  msg.LED1 = Value;   // State of the LED
  connection.send(JSON.stringify(msg));
}  

</script>
</head>

<body>
<div style='text-align:left;display:inline-block;color:#eaeaea;min-width:304px;'>
  <h1>Bewässerungssystem</h1>
  <h3>JaTiMa - Webserver</h3>
  <div>  <br>
  <h2>Informationen</h2>
  Temperatur: <span id="TEMP">...</span><br>
  Luftfeuchtigkeit: <span id="LUFE">...</span><br>
  Erdfeuchtigkeit: <span id="ERFE">...</span><br>
  Helligkeit: <span id="HELI">...</span><br>
  Pumpe: <span id="PUMP">...</span><br>
  UV/Licht: <span id="LICH">...</span><br>
  Lüfter: <span id="LUER">...</span><br>
<!-- <button id="BU_ON">on</button> <br>
  <button id="BU_OFF">off</button> <br>
  <button id="BU_TOGGLE">toggle</button> <br>-->
  </div>
  <br>
  Debug Verbindungsstatus <span id="READY_STATE">...</span>
  </div>
</body>
</html>
)=====";
