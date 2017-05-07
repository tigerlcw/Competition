<!DOCTYPE html>
<html>
<head>

    <meta charset="utf-8" />
<meta name="viewport" content="width=device-width, user-scalable=no">

    <title>High진로</title>
    <link href="./css/layout.css" rel="stylesheet" type="text/css">
<style>
        #topMenu {            
                height: 30px; 
                width: 350px; 
        }
        #topMenu ul li {                       
                list-style: none;          
                color: white;              
                background-color: #3300FF;  
                float: left;              
                line-height: 30px;          
                vertical-align: middle;    
                text-align: center;        
        }
        #topMenu .menuLink {                               
                text-decoration:none;                     
                color: white;                              
                display: block;                            
                width: 150px;                              
                font-size: 12px;                         
                font-weight: bold;                         
                font-family: "Trebuchet MS", Dotum, Arial; 
        }
        #topMenu .menuLink:hover {           
                color: black;                  
                background-color: #CCFFFF;    
        }
</style>
<center>
<nav id="topMenu" >
        <ul>
                <li><a class="menuLink" href="list.html"self>정보제공</a></li>
                <li><a class="menuLink" href="#" onClick="window.open('http://www.career.go.kr/cnet/iframe/School.do?apiKey=ddc43d3fa6215937aa01a8c314f14fe2&gubun=high_list','학교검색','resizable=no scrollbars=yes width=700 height=500  top=0,left=0 ')">학교검색</a></li>
                <li><a class="menuLink" href="list2.html"self>공지사항</a></li>
<li><a class="menuLink" href="http://m.map.daum.net/" target="_blank" title="다음지도 열기">지도검색</a></li>
        
        </ul>
</nav>


</head>
    <body background="q1.jpg">
        <form action="search.php" method="get">

 <br>
        <h1><font size="9">"High진로"</font></h1>
        <h2><font size="6", font color="#FF0601">정보를 입력해주세요!!!</font></h2>

        <ul>
  
                <li><label><font size="5">관심분야:</font><input type="text" name="hobby" /></label></li>
            <br><li>
                <font size="5">거주지:</font>
                <select name="addr" size=1>
                    <option value=1 SELECTED>강남구</option>
                    <option value=2>강동구</option>
                    <option value=3>강북구</option>
                    <option value=4>강서구</option>
                    <option value=5>관악구</option>
                    <option value=6>광진구</option>
                    <option value=7>구로구</option>
                    <option value=8>금천구</option>
                    <option value=9>노원구</option>
                    <option value=10>도봉구</option>
                    <option value=11>동대문구</option>
                    <option value=12>동작구</option>
                    <option value=13>마포구</option>
                    <option value=14>서대문구</option>
                    <option value=15>서초구</option>
                    <option value=16>성동구</option>
                    <option value=17>성북구</option>
                    <option value=18>송파구</option>
                    <option value=19>양천구</option>
                    <option value=20>영등포구</option>
                    <option value=21>용산구</option>
                    <option value=22>은평구</option>
                    <option value=23>종로구</option>
                    <option value=24>중구</option>
                    <option value=25>중랑구</option>
                </select>
            </li>
<br>
                <li><label><font size="5">내신(%):</font><input type="text" name="score" /></label></li>

           <font size="2", font color="#FF0601">현재는 서울지역 학교만 검색가능합니다.<br>내신입력시 서울시 성적 산출 기준인 %로 입력해주세요.</font>
            <li><label><input type="radio" value="네" name="letter">네</label>
                <label><input type="radio" value="네" name="letter">아니요</label><br>
              ※일반전형 기준입니다.※
            </li>
            <input type="submit" value="입력"></li>
        </ul>
        </form>
    </center>
</section>





<aside></aside>
<br><br><br>
<footer>
    <p>Copyright ⓒ 2015 by LCW </p>
<p>버전 1.1.5 (BETA) </p>
</footer>

</body>
</html>
