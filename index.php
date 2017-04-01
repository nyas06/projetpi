<html>
    <head>
    </head>
    <body>
        <script src="lib/jquery-3.2.0.min.js"></script>
        <div id="content"></div>
    </body>
    
    <script>
        var values = [];
        var output
        $( document ).ready(function() {
            function timer(){
                $.get( "sensor/receiveValueSensor.php", function( data ) {
                    values.push(data);
                    output += data+',';
                    $( "#content" ).html(output);                  
                });
            }
            setInterval(timer,200);
        });
    </script>
</html>
