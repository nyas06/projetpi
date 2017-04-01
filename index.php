<html>
    <head>
    </head>
    <body>
        <div id="content"></div>
    </body>
    <script src="lib/jquery-3.2.0.min.js" async></script>
    <script>
        $(function() {
            function timer(){
                $('#content').html("<?=exec('sudo python ../prod/testSensor2.py')." cm ".date()?>");
            }
            setInterval(timer,1000);
        });
    </script>
</html>
