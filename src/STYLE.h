char style[] PROGMEM = R"===(
@import url('https://fonts.googleapis.com/css2?family=Bungee&display=swap');
body {
  color: #000;
  background: #343434;
  line-height: 150%;
}
.titulo{
  font-family: bungee;
  line-height: 20px;
  text-shadow: 2px 2px 5px #343434;
}
.quadrado{
  padding-top: 20px;
  padding-bottom: 1vh;
  background: #fff;
  border-radius: 25px;
  width: 30rem;
  margin-top: 15px;
  margin-bottom: 15px;
}

.wrapper svg {
}

.wrap {
  min-height: 100vh;
  max-width: 720px;
  margin: 0 auto;
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: center;
  
  .half {
    width: 50%;
    padding: 32px 0;
  }
}

.title {
  font-family: sans-serif;
  line-height: 24px;
  display: block;
  padding: 8px 0;
}

.readout {
  margin-top: 32px;
  line-height: 180%;
}

#values {
 font-family: monospace;
  line-height: 150%;
}

.link {
  margin-top: 16px;
  
  a {
    color: MediumSlateBlue;
  }
}

)===";