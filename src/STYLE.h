char style[] PROGMEM = R"===(
@import url('https://fonts.googleapis.com/css2?family=Sacramento&display=swap');
body {
  color: #000;
  background:  #e0e0e0;
  line-height: 150%;
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100vh;
  padding: 24px;
  font-family: Sacramento;
}
.titulo{
  font-size: 72px;
  color: #5d5d5d;
  line-height: 20px;
  text-shadow: 2px 2px 5px #34343434;
}
.quadrado{
  width: 100%;
  max-width: 500px;
  box-shadow:  40px 40px 75px #acacac,
             -40px -40px 75px #ffffff;
  margin: 0 auto;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
  padding: 24px;
  gap: 6px;
  border-radius: 32px;
 
}
p{
  font-size: 24px;
}
.colorPicker{
  display: block;
  width: 100%;
}
)===";