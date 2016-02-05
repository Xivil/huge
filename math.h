重さ
w=mg
w＝重さ
m=質量
g=重力加速度(-9.8ms^2)
重さとは、その物体にかかる重力のこと
重さは質量に重力加速度をかけることで出力できる
単位はkg*m/sだが読みづらいという経緯からニュートン（記号N）で表すことになりました

//	オブジェクトの重さを質量に基づいて計算
//	mass＝オブジェクトの質量、grav＝重力加速度
//	出力重さのベクトルを表す3つの要素
km::Vector3 calcWeight3D(float mass, float grav){
	km::Vector3 ret;
	ret.y = mass * grav;
	return ret;
}



ニュートン
1N=1kg*m/s^2
1N=0.2248lbs(ポンド(重さの単位))

垂直抗力
重力によって鉛直下方に引っ張られると同時に地面から受ける力
1.112キロのボールが傾斜30度の斜面を転がっているときの斜面の垂直抗力を求める
-1.112N*cos(30)=-0.963N

摩擦力
氷の上で滑りやすかったりするのは摩擦力が関係している
摩擦力は二つある
静止摩擦力
物体が滑り出さないようにする力
運動摩擦力
動いている物体の運動を阻止しようとする力
摩擦力を計算する場合は必ず静止摩擦力を先に計算する。
物体に働く力の合計が静止摩擦力より小さければ物体は滑らないが力の合計が静止摩擦力を上回ると部たちは滑り始める

摩擦力はμを使って表す
静止摩擦力＝μs
運動摩擦力＝μk

最大静止摩擦力＝静止摩擦係数*垂直抗力
Fs＝μsN

運動摩擦力＝運動摩擦係数＊垂直抗力
Fk＝μkN

//	斜面上の物体が滑るかどうかの判定
//　　angle＝斜面の現在の傾斜角度、weight＝物体の重さ、fric_coeff＝2面間の静止摩擦係数
bool checkForMotion(floatangle, float weight, float fric_coeff){
	//	斜面のつい直効力の計算
	float normal = weight*cosf(angle*PI/180);
	//	垂直抗力に垂直な力の計算
	float perpForce = weight*sinf(angle*PI/180);
	//	物体を静止させておこうとする最大静止摩擦力の計算
	float stat_friction = fric_coeff*normal;
	//	物体が滑り出す場合はtrueを、そうでなければfalseを返す
	return perpForce > stat_friction;
}

//	斜面上の物体が滑り出す場合の加速度の計算
//	angle＝斜面の現在の傾斜角度、weight＝物体の重さ、fric_coeff＝2面間の運動摩擦係数、mass＝物体の質量
float calcAccel(float angle, float weight, float fric_coeff,float mass){
	//	斜面のつい直効力の計算
	float normal = weight*cosf(angle*PI/180);
	//	垂直抗力に垂直な力の計算	
	float perpForce = weight*sinf(angle*PI/180);
	//	物体の運動を阻止しようとする運動摩擦力
	float kin_friction = fric_coeff* normal;
	//	物体に動く合力の計算
	float total_force = perpForce- kin_friction;
	//	物体の加速度を返す
	return total_force / mass;
}