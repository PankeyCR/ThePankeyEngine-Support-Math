
#pragma once

	#include "Vector3f.hpp"

	namespace pankey{

		namespace Support{

			namespace Math{

				class Vector2f{
					public:

						float x = 0;
						float y = 0;

						Vector2f(float xx, float yy){
							this->x = xx;
							this->y = yy;
						}

						Vector2f(){
							this->x = this->y = 0;
						}

						Vector2f(const Vector2f& a_vector){
							this->x = a_vector.x;
							this->y = a_vector.y;
						}

						const static Vector2f ZERO(){
							return Vector2f(0,0);
						}

						const static Vector2f UNIT_XY(){
							return Vector2f(1.0f, 1.0f);
						}

						void set(float a_x_value, float a_y_value){
							this->x = a_x_value;
							this->y = a_y_value;
						}

						void set(const Vector2f& a_vector){
							this->x = a_vector.x;
							this->y = a_vector.y;
						}

						void add(const Vector2f& a_vector){
							this->x += a_vector.x;
							this->y += a_vector.y;
						}

						void add(float a_x_value, float a_y_value){
							this->x += a_x_value;
							this->y += a_y_value;
						}

						void add(float a_scalar){
							this->x += a_scalar;
							this->y += a_scalar;
						}

						float dot(const Vector2f& a_vector){
							return (this->x * a_vector.x) + (this->y * a_vector.y);
						}

						float determinant(const Vector2f& a_vector){
							return (this->x * a_vector.y) - (this->y * a_vector.x);
						}

						float determinant(float a_x_value, float a_y_value){
							return (this->x * a_y_value) - (this->y * a_x_value);
						}

						void interpolate(const Vector2f& a_finalVec, float a_changeAmnt){
							this->x = (1 - a_changeAmnt) * this->x + a_changeAmnt * a_finalVec.x;
							this->y = (1 - a_changeAmnt) * this->y + a_changeAmnt * a_finalVec.y;
						}

						void interpolate(const Vector2f& a_beginVec, const Vector2f& a_finalVec, float a_changeAmnt){
							this->x = (1 - a_changeAmnt) * a_beginVec.x + a_changeAmnt * a_finalVec.x;
							this->y = (1 - a_changeAmnt) * a_beginVec.y + a_changeAmnt * a_finalVec.y;
						}

						static bool isValidVector(const Vector2f& a_vector){
						//  if (Float.isNaN(vector.x) ||
						//      Float.isNaN(vector.y)) return false;
						//  if (Float.isInfinite(vector.x) ||
						//      Float.isInfinite(vector.y)) return false;
						return true;
						}

						float length() const{
							return sqrt(lengthSquared());
						}

						float lengthSquared() const{
							return (this->x * this->x) + (this->y * this->y);
						}

						float distanceSquared(const Vector2f& a_vector){
							double dx = this->x - a_vector.x;
							double dy = this->y - a_vector.y;
							return (float) (dx * dx + dy * dy);
						}

						float distanceSquared(float a_otherX, float a_otherY){
							double dx = this->x - a_otherX;
							double dy = this->y - a_otherY;
							return (float) (dx * dx + dy * dy);
						}

						float distance(const Vector2f& a_vector){
							return sqrt(distanceSquared(a_vector));
						}

						float distance(float a_x_value, float a_y_value){
							return sqrt(distanceSquared(a_x_value, a_y_value));
						}

						void mult(float a_scalar){
							this->x *= a_scalar;
							this->y *= a_scalar;
						}

						void mult(const Vector2f& a_vector){
							this->x *= a_vector.x;
							this->y *= a_vector.y;
						}

						void mult(float a_mulX, float a_mulY){
							this->x *= a_mulX;
							this->y *= a_mulY;
						}

						void divide(float scalar){
							this->x /= scalar;
							this->y /= scalar;
						}

						void divide(const Vector2f& a_vector){
							this->x /= a_vector.x;
							this->y /= a_vector.y;
						}

						void divide(float a_x_value, float a_y_value){
							this->x /= a_x_value;
							this->y /= a_y_value;
						}

						Vector2f negate(){
							this->x = -this->x;
							this->y = -this->y;
							return *this;
						}

						void subtract(float a_scalar){
							this->x -= a_scalar;
							this->y -= a_scalar;
						}

						void subtract(const Vector2f& a_vector){
							this->x -= a_vector.x;
							this->y -= a_vector.y;
						}

						void subtract(float a_valX, float a_valY){
							this->x -= a_valX;
							this->y -= a_valY;
						}

						void normalize(){
							float i_lengthN = this->length();
							if (lengthN != 0) {
								this->divide(i_lengthN);
								return;
							}

							this->divide(1);
						}

						float smallestAngleBetween(const Vector2f& a_vector){
							float dotProduct = dot(a_vector);
							float angle = acos(dotProduct);
							return angle;
						}

						float angleBetween(const Vector2f& a_vector){
							float angle = atan2(a_vector.y, a_vector.x)
									- atan2(this->y, this->x);
							return angle;
						}

						float getX(){
							return this->x;
						}

						void setX(float xx){
							this->x = xx;
						}

						float getY(){
							return this->y;
						}

						void setY(float yy){
							this->y = yy;
						}

						float getAngle(){
							return atan2(this->y, this->x);
						}

						void zero(){
							this->x = 0;
							this->y = 0;
						}

						void rotateAroundOrigin(float a_pi, float a_angle, bool a_cw){
							if (a_cw){
								a_angle = -a_angle;
							}
							float i_rad = (a_pi/180.0f) * a_angle;
							float i_newX = cos(i_rad) * this->x - sin(i_rad) * this->y;
							float i_newY = sin(i_rad) * this->x + cos(i_rad) * this->y;
							this->x = i_newX;
							this->y = i_newY;
						}

						void rotate(float a_pi, float a_angle){
							float i_rad = (a_pi/180.0f) * a_angle;
							float i_coseno = (float)cos(i_rad);
							float i_seno = (float)sin(i_rad);
							float i_xx = this->x * i_coseno - this->y * i_seno;
							float i_yy = this->x * i_seno + this->y * i_coseno;
							this->x = i_xx;
							this->y = i_yy;
						}

						Vector2f& operator=(const Vector2f& a){
							this->x = a.x;
							this->y = a.y;
							return *this;
						}

						Vector2f& operator=(const float& a){
							this->x = a;
							this->y = a;
							return *this;
						}

						Vector2f& operator=(const float a[2]){
							this->x = a[0];
							this->y = a[1];
							return *this;
						}

						Vector2f& operator=(const int& a){
							this->x = (float)a;
							this->y = (float)a;
							return *this;
						}

						Vector2f& operator=(const double& a){
							this->x = (float)a;
							this->y = (float)a;
							return *this;
						}

						bool operator==(const Vector2f& a){
							if(this->x == a.x && this->y == a.y){
							return true;
							}
							return false;
						}

						bool operator!=(const Vector2f& a){
							if(this->x != a.x && this->y != a.y){
								return true;
							}
							return false;
						}

						Vector2f operator+(const Vector2f& a) const{
							return Vector2f(this->x+ a.x ,this->y + a.y);
						}
						Vector2f operator+(const float& a) const{
							return Vector2f(this->x+a ,this->y+a);
						}
						Vector2f operator+(const int& a) const{
							return Vector2f(this->x+(float)a ,this->y+(float)a);
						}
						Vector2f operator+(const double& a) const{
							return Vector2f(this->x+(float)a ,this->y+(float)a);
						}

						Vector2f operator-(const Vector2f& a) const{
							return Vector2f(this->x- a.x ,this->y - a.y);
						}
						Vector2f operator-(const float& a) const{
							return Vector2f(this->x-a ,this->y-a);
						}
						Vector2f operator-(const int& a) const{
							return Vector2f(this->x- (float)a ,this->y-(float)a);
						}
						Vector2f operator-(const double& a) const{
							return Vector2f(this->x- (float)a ,this->y-(float)a);
						}

						Vector2f operator*(const Vector2f& a) const{
							return Vector2f(this->x* a.x ,this->y * a.y);
						}
						Vector2f operator*(const float& a) const{
							return Vector2f(this->x* a ,this->y* a);
						}
						Vector2f operator*(const int& a) const{
							return Vector2f(this->x*(float)a ,this->y*(float)a);
						}
						Vector2f operator*(const double& a) const{
							return Vector2f(this->x*(float)a ,this->y*(float)a);
						}

						Vector2f operator/(const Vector2f& a) const{
							return Vector2f(this->x/ a.x ,this->y / a.y);
						}
						Vector2f operator/(const float& a) const{
							return Vector2f(this->x/ a ,this->y/ a);
						}
						Vector2f operator/(const int& a) const{
							return Vector2f(this->x/(float)a ,this->y/(float)a);
						}
						Vector2f operator/(const double& a) const{
							return Vector2f(this->x/(float)a ,this->y/(float)a);
						}

						Vector2f operator+=(const Vector2f& a) {
							this->x += a.x;
							this->y += a.y;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator+=(const float& a) {
							this->x += a;
							this->y += a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator+=(const int& a) {
							this->x += (float)a;
							this->y += (float)a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator+=(const double& a) {
							this->x += (float)a;
							this->y += (float)a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator-=(const Vector2f& a) {
							this->x -= a.x;
							this->y -= a.y;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator-=(const float& a) {
							this->x -= a;
							this->y -= a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator-=(const int& a) {
							this->x -= (float)a;
							this->y -= (float)a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator-=(const double& a) {
							this->x -= (float)a;
							this->y -= (float)a;
							return Vector2f(this->x,this->y);
						}

						Vector2f operator*=(const Vector2f& a) {
							this->x *= a.x;
							this->y *= a.y;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator*=(const float& a) {
							this->x *= a;
							this->y *= a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator*=(const int& a) {
							this->x *= (float)a;
							this->y *= (float)a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator*=(const double& a) {
							this->x *= (float)a;
							this->y *= (float)a;
							return Vector2f(this->x,this->y);
						}

						Vector2f operator/=(const Vector2f& a) {
							this->x /= a.x;
							this->y /= a.y;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator/=(const float& a) {
							this->x /= a;
							this->y /= a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator/=(const int& a) {
							this->x /= (float)a;
							this->y /= (float)a;
							return Vector2f(this->x,this->y);
						}
						Vector2f operator/=(const double& a) {
							this->x /= (float)a;
							this->y /= (float)a;
							return Vector2f(this->x,this->y);
						}
				};

			}

		}

	}