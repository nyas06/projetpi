<html>
    <head>
    </head>
    <body>
        <script src="lib/jquery-3.2.0.min.js"></script>
        <div id="content"></div>
    </body>
    
    <script>
        $( document ).ready(function() {
            function timer(){
                $.get( "receiveValueSensor/receiveValueSensor.php", function( data ) {
                    $( "#content" ).html( data );
                });
            }
            setInterval(timer,1000);
        });
    </script>
</html>
