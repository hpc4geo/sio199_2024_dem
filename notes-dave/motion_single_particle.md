# Motion of a Single Particle

Dave A. May  
Oct 18, 2024  _Revision 1_



## 1. Single Point Mass
Given a point with mass $m$, position $\mathbf x$, velocity $\mathbf v$ and acceleration $\mathbf a$, the equations of motion are given by:

1. Conservation of _linear momentum_
$$
m \frac{d \mathbf a}{dt} = \mathbf F_\text{external}
$$
2. The definition of velocity
$$
\frac{d\mathbf x}{dt} = \mathbf v
$$

As a notational short-hand, let
$$
\frac{d s}{dt} = \dot{s}, \quad \text{and } \quad \frac{d^2 s}{dt^2} = \ddot{s}
$$

Note that
$$
	\mathbf a = \dot{\mathbf v} = \ddot{\mathbf x}.
$$

With these definitions we write the conservation of linear momentum and def. of velocity as the following coupled system of ordinary differential equations:

$$
\begin{pmatrix}
\dot{\mathbf x} \\
\dot{\mathbf v}
\end{pmatrix} =
\begin{pmatrix}
\mathbf v \\
\dfrac{1}{m} \mathbf F_\text{external}
\end{pmatrix}
$$

We will let $\mathbf Y = (\mathbf x, \mathbf v)^T$, then the above equation becomes

$$
	\dot{\mathbf Y} = \mathbf H(\mathbf Y, t).
$$


## 2. Single Particle of Finite Size
Given a particle with mass $m$, position $\mathbf x$, velocity $\mathbf v$ and acceleration $\mathbf a$, the equations of motion are given by (as before):

1. Conservation of _linear momentum_
$$
m \frac{d \mathbf a}{dt} = \mathbf F_\text{external}
$$
2. The definition of velocity
$$
\frac{d\mathbf x}{dt} = \mathbf v
$$


We assume the particle is finite in size, and is circular (2D) (or spherical in 3D) with a radius of $r$.We further assume that the particle is non-deformable.
The dynamics associated with the rotation of the finite sized particle are given by 

1. Conservation of _angular momentum_
$$
I \frac{d \mathbf \omega}{dt} = \mathbf \tau_\text{external},
$$
where $\mathbf \omega$ is the angular velocity about the center of mass and $I$ is the moment of inertia. Since the particles are spherical and non-deforming, the center of mass is the center of the sphere.
2. The definition of angular velocity is
$$
\frac{d\mathbf \omega}{dt} = \mathbf \theta,
$$
where $\mathbf \theta$ is the angle / orientation of the particle.

As a notational short-hand, let
$$
\frac{d s}{dt} = \dot{s}, \quad \text{and } \quad \frac{d^2 s}{dt^2} = \ddot{s}
$$

Note that
$$
	\mathbf a = \dot{\mathbf v} = \ddot{\mathbf x}.
$$

With these definitions we write the conservation of linear momentum and def. of velocity as the following coupled system of ordinary differential equations:

$$
\begin{pmatrix}
\dot{\mathbf x} \\
\dot{\mathbf v} \\
\dot{\mathbf \theta} \\
\dot{\mathbf \omega}
\end{pmatrix} =
\begin{pmatrix}
\mathbf v \\
\dfrac{1}{m} \mathbf F_\text{external} \\
\mathbf \omega \\
\dfrac{1}{I} \mathbf \tau_\text{external}
\end{pmatrix}
$$

We will let $\mathbf Y = (\mathbf x, \mathbf v)^T$, then the above equation becomes

$$
	\dot{\mathbf Y} = \mathbf H(\mathbf Y, t).
$$



## 3. The "satellite" problem

This problem involes two particles, but only one of them is moving point. Hence the system behaves like a single body problem and thus there are no particle-particle interactions. This problem does not invovle collisions with a solid boudy (or other particles).
The exmaple is associated with orbital mechanics and Kepler's law of planetary motion.

### 3.1 Problem statement

Consider the evolution of a satellite of satellite $m_s$ around the Earth (mass $m_e$). Assume the Earth and the satelite bodies can be approximated by points. We will use a 2D Cartesian coordinates system, $\mathbf x = (x, y)$ and we will assume the Earth is located at the origin $\mathbf x = (0, 0)$.

The force $\mathbf F_\text{external}$ is given by 
$$
\mathbf F_\text{external} = - \frac{G m_e m_s}{R^3} \mathbf x,
\qquad R = \sqrt{x^2 + y^2}.
$$

The angular velocity $\omega$ of the satellite is given by 
$$
	\omega = \sqrt{\frac{G m_e}{x}}.
$$
The orbital period $T$ is given by 
$$
	T = \frac{2 \pi}{\omega}
$$

The satellite is initially located at position $\mathbf x(t=0) = (0, R_0) = \mathbf x_0$.
With all these assumptions, the satelitte should orbit the Earth in a circular path, hence the distance between the Earth and the satellite should remain constant over time and have the value $R_0$. That is, $R(t) = \sqrt{ x(t)^2 + y(t)^2} = R_0$.

The initial velocity is given by
$$
	\mathbf v(t=0) = \omega \begin{pmatrix}
	y(t=0) \\
	-x(t=0)
	\end{pmatrix},
$$
that is, the satellite is initially rotating in a clock-wise direction.

### 3.2 Tasks

- Define $\mathbf Y$.
- Write the governing equations in the form $\dot{\mathbf Y} = \mathbf H(\mathbf Y, t)$. Write down the expression defining $\mathbf H$.
- Assume the following parameters
	* $R = 1000 \times 10^3$ m (160 - 2,000 km is typical)
	* $m_e = 5.97219 \times 10^{24}$ kg
	* $m_s = 2500$ kg
	* $G = 6.67 \times 10^{−11}$ N m$^{2}$ kg$^\text{-2}$
- We will denote the initial condition for $\mathbf Y(t)$ at time $t=0$ via
$$
	\mathbf Y(t=0) = \mathbf Y^0.
$$
Write out the elements of the vector $\mathbf Y^0$.
- Write a code which solves $\dot{\mathbf Y} = \mathbf H(\mathbf Y, t)$ with initial condition $\mathbf Y^0$.

### 3.3 References

* [https://colorado.pressbooks.pub/introorbitalmechanics/chapter/copy-of-chapter-1__editing/](https://colorado.pressbooks.pub/introorbitalmechanics/chapter/copy-of-chapter-1__editing/) See section "THE TWO BODY EQUATION OF MOTION"
* [https://zingale.github.io/comp_astro_tutorial/basics/ODEs/ODEs-partI.html](https://zingale.github.io/comp_astro_tutorial/basics/ODEs/ODEs-partI.html)


## 4. The "bouncing ball" problem

This problem involes one particles, and involves modelling the collison of the point with a solid boudy boundary. The ball has an assumed radius of $r$. Despite its finite size, we will ingore angular momentum.
The example is related to Newtonian mechanics.

### 4.1 Problem statement

We wish to model the bouncing of an elastic ball.
The ball is not perfectly elastic, hence some energy is dissipated after each time the ball bounces.

The ball is treated as a point mass with mass $m$. The ball falls under gravity, thus from Newton's second law we have the conservation of linear momentum

$$
	m \mathbf g = m \ddot{\mathbf x}(t).
$$

The ball continues to fall under gravity until it comes in to contact
with a horizontal surface located at $y = y_w = 0$.
Let's assume the ball is initially located at 
$$
	\mathbf x(t=0) = (0, h)
$$
and has velocity
$$
	\mathbf v(t=0) = (0, 0).
$$

As the ball falls, at some instant in time it will overlap / intersection the boundary. We will denote the distance which it overlaps by as ${\mathbf x}_\text{pen}(t)$ which is defined as
$$
{\mathbf x}_\text{pen}(t) = (0, \delta),
$$
where
$$
	\delta = 
	\begin{cases}
    0,              & \text{for } y(t) - r > y_w \\
    y_w - (y(t)-r), & \text{for } y(t) - r < y_w.
	\end{cases}
$$
Note that for all time $t$, $\delta \ge 0$.

To model the collison between the ball and a horizontal surface,
we introduce an damped elastic restoring force related to ${\mathbf x}_\text{pen}(t)$. When collison occurs, the conservation of linear momentum is modified according to
$$
	m \mathbf g -k_w {\mathbf x}_\text{pen}(t) -c_w \dot{\mathbf x}_\text{pen}(t) = m \ddot{\mathbf x}(t).
$$
The constants $k_w$ is the elastic stiffness associated with the collison between the ball and the wall, and $c_w$ is associated with the viscous damping (leading to energy dissipation).

### 4.2 Tasks

- Write down the equations in the form $\dot{\mathbf Y} = \mathbf H$, indicating the entries of $\mathbf H$.
- Take $m = 0.2$ kg, $r = 0.01$ m. Use nominal values for the spring constant ($k_w$) and damping constant ($c_w$) given  by $k_w = 5000$, and $c_w = 5$, solve the ODEs for $t = \in (0, 2]$ s.

### 4.3 References

* Kevin Gildea, [https://kevgildea.github.io/blog/EOM-contact-modelling](https://kevgildea.github.io/blog/EOM-contact-modelling). The example is taken straight from here.

<!--

## 5. The "spinning bouncing ball" problem

Objective:  Augment problem "bouncing ball" to include the conservation of angular momentum.

* $\mathbf Y = (\mathbf x, \mathbf v, \theta, \omega)$.

* The initial position, angle is $\mathbf x^0 = ( 0, h)$, $\theta^0 = 0$.

* The initial condition is $\mathbf v^0 = (1, -1)$, $\omega^0 = 0$. The oblique collison should result in the ball starting to spinning after the impact.

$$
I \frac{d \omega}{dt} = 
	\begin{cases}
    0,              & \text{no colision} \\
    \tau_\text{collision}, & \text{during collision}.
   \end{cases}
$$

The surface the ball bounces on has a normal $\hat{\mathbf n} = (0, 1)$.

$$
	\mathbf v_\text{tangential} = \mathbf v - (\mathbf v \cdot \mathbf n) \mathbf n
$$

-->

