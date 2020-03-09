// Global

NetAddr("127.0.0.1", 9005).sendMsg("/bg_color", 0.asInteger,0.asInteger,0.asInteger,25.asInteger) //  r,g,b,a

// Particles

NetAddr("127.0.0.1", 9005).sendMsg("/particleView", 0.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/particleView", 1.asInteger);

(
NetAddr("127.0.0.1", 9005).sendMsg("/bounce/x/start", 100.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/bounce/y/start", 100.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/bounce/x/end", 700.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/bounce/y/end", 800.asInteger);
)

NetAddr("127.0.0.1", 9005).sendMsg("/particleNeighborhood", 20.asInteger);

NetAddr("127.0.0.1", 9005).sendMsg("/pushParticles", 0.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/pushParticles", 1.asInteger);

NetAddr("127.0.0.1", 9005).sendMsg("/push/x", 200.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/push/y", 100.asInteger);

NetAddr("127.0.0.1", 9005).sendMsg("/forceRadius", 100.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/forceScale", 10.asInteger);


NetAddr("127.0.0.1", 9005).sendMsg("/dotColor", 25.asInteger,25.asInteger,255.asInteger,255.asInteger)
NetAddr("127.0.0.1", 9005).sendMsg("/conColor", 25.asInteger,25.asInteger,255.asInteger,255.asInteger)

// Sketch
(
NetAddr("127.0.0.1", 9005).sendMsg("/sketchView", 1.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/sketch/x", 520.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/sketch/y", 400.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/elasticityMin", 0.1.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/elasticityMax", 1.1.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/dampingMin", 0.1.asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/dampingMax", 1.1.asInteger);
)
(
NetAddr("127.0.0.1", 9005).sendMsg("/sketch/x", rrand(0,900).asInteger);
NetAddr("127.0.0.1", 9005).sendMsg("/sketch/y", rrand(0,900).asInteger);
)