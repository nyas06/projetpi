<html>
    <head>
    </head>
    <body>
        <script src="lib/jquery-3.2.0.min.js"></script>
        <div id="content" style='font-size:1.5em'></div>
    </body>
    
    <script>
        //var values = [];
        var output = ''
        var retourALaLigne = 0
        $( document ).ready(function() {
            function timer(){
                $.get( "sensor/receiveValueSensor.php", function( data ) {
                    if (data !== '0') {
                        retourALaLigne = retourALaLigne + 1;
                        //values.push(data);
                        if (retourALaLigne === 20) {
                            retourALaLigne = 0
                            output += data+',<br>';
                        } else {
                            output += data+',';
                        }
                        $( "#content" ).html(output);
                    }                
                });
            }
            setInterval(timer,500);
        });
    </script>
</html>
