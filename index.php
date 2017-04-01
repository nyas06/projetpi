<html>
    <head>
        <link rel="stylesheet" type="text/css" href="style/style.css">
    </head>
    <body>
        <script src="lib/jquery-3.2.0.min.js"></script>
        <!--<div id="content" style='font-size:1.5em'></div>-->
        <div id="cercle"></div>
    </body>
    
    <script>
        //var values = [];
        var output = ''
        var retourALaLigne = 0
        $( document ).ready(function() {
            function timer(){
                $.get( "sensor/receiveValueSensor.php", function( data ) {
                    if (data >= 2) {
                        /*
                        retourALaLigne = retourALaLigne + 1;
                        //values.push(data);
                        if (retourALaLigne === 20) {
                            retourALaLigne = 0
                            output += data+',<br>';
                        } else {
                            output += data+',';
                        }
                        $( "#content" ).html(output);
                        */
                        $( "#cercle" ).css({"width": (data*2)+"px", "height": (data*2)+"px"});
                    }                
                });
            }
            setInterval(timer,500);
        });
    </script>
</html>
