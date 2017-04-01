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
                $('#content').html("<?=exec('sudo python ../prod/testSensor2.py')." cm ".date()?>");
            }
            setInterval(timer,1000);
        });
    </script>
</html>
