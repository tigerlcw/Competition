var express = require('express')
var bodyParser = require('body-parser')
var fs = require('fs')
var path = require('path')
var https = require('http')
var ejs = require('ejs')
var app = express()

/*var options = {
    key: fs.readFileSync('key.pem'),
    cert: fs.readFileSync('cert.pem')
};*/
app.engine('html', require('ejs').renderFile);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
app.use(express.static(path.join(__dirname, '/public')));

https.createServer(/*options,*/ app).listen(3000,3030,(err)=>{
    if(err){
        console.log('Server Error!')
        throw err
    }
    else {
        console.log('서버가 정상 실행중 입니다. 포트는 3000입니다.');
    }
});

app.get('/', (req, res)=>{
    res.render('about')
});
app.get('/about',(req, res)=>{
res.render('index')
});
