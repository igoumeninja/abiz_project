Γειά σου Γιαννη ;)

Clone the repository inside openframeworks:  =of/apps/myApps=

Here is my path: =/home/aris/Software/oF/of_v0.11.0_linux64gcc6_release/apps/myApps/abiz_project=

*Send OSC messages*

NetAddr("127.0.0.1", 9005).sendMsg("/particleView", 1.asInteger)

NetAddr("127.0.0.1", 9005).sendMsg("/particleView", 0.asInteger)
NetAddr("127.0.0.1", 9005).sendMsg("/particleView", 1.asInteger)

NetAddr("127.0.0.1", 12345).sendMsg("/particle", "bounce", 100,100,500,900)
NetAddr("127.0.0.1", 12345).sendMsg("/particle", "bounce", 100,100,800,900)

NetAddr("127.0.0.1", 12345).sendMsg("/particle", "particleNeighborhood", 4)
NetAddr("127.0.0.1", 12345).sendMsg("/particle", "particleNeighborhood", 20)




NetAddr("127.0.0.1", 12345).sendMsg("/particle", "forceRadius", 35.asInteger)

NetAddr("127.0.0.1", 12345).sendMsg("/particle", "forceScale", 100.asInteger)

NetAddr("127.0.0.1", 12345).sendMsg("/particle", "pushParticles", 1.asInteger)
NetAddr("127.0.0.1", 12345).sendMsg("/particle", "pushParticles", 0.asInteger)


NetAddr("127.0.0.1", 12345).sendMsg("/particle", "push", 300.asInteger, 200.asInteger)

NetAddr("127.0.0.1", 12345).sendMsg("/particle", "lineOpacity", 2)
NetAddr("127.0.0.1", 12345).sendMsg("/particle", "push", 150,150)
