#include "game_level.h"

void from_json(const json &j, GameLevel &l)
{
    j.at("level_name").get_to(l.name);
    j.at("level_order").get_to(l.order);
    j.at("init_lifepoints").get_to(l.player_lifepoints);
    //Divide the json props to 2 different properties
    j.at("asteroids_props").get_to(l.asteroids_props);
    j.at("asteroids_props").get_to(l.asteroids_amount);
    j.at("ship_config").get_to(l.ship_config);
    j.at("env_resistance").get_to(l.env_resistance);
}


void from_json(const json &j, Vec2d &v)
{
    v = {j.at("x"), j.at("y")};
}

void from_json(const json &j, Color &c)
{
    c = {j[0], j[1], j[2], 0};
}

void from_json(const json &j, VerticesArray &s)
{
    for(auto const& v: j)
    {
        s.push({v.at("x"), v.at("y")});
    }
}

void from_json(const json &j, AsteroidsAmount &a)
{
    j.at("BIG").at("amount").get_to(a[AsteroidSize::BIG]);
    j.at("MEDIUM").at("amount").get_to(a[AsteroidSize::MEDIUM]);
    j.at("SMALL").at("amount").get_to(a[AsteroidSize::SMALL]);
}

void from_json(const json &j, AsteroidsFactoryDesc &d)
{
    j.get_to(d.polygone_desc);
    j.at("max_velocity").get_to(d.max_vel);
    j.at("max_angle_velocity").get_to(d.max_angle_vel);
    j.at("min_nb_split").get_to(d.min_nb_split);
    j.at("max_nb_split").get_to(d.max_nb_split);
    j.at("color").get_to(d.color);
}

void from_json(const json &j, AsteroidsProps &p)
{
    j.at("BIG").get_to(p[AsteroidSize::BIG]);
    j.at("MEDIUM").get_to(p[AsteroidSize::MEDIUM]);
    j.at("SMALL").get_to(p[AsteroidSize::SMALL]);
}

void from_json(const json &j, RandomPolygoneDesc &d)
{
    j.at("min_radius").get_to(d.min_radius);
    j.at("max_radius").get_to(d.max_radius);
    j.at("granularity").get_to(d.granularity);
    j.at("min_angle_vary").get_to(d.min_angle_vary);
    j.at("max_angle_vary").get_to(d.max_angle_vary);
}

void from_json(const json &j, ShipConfig &s)
{
    j.at("init_position").get_to(s.init_position);
    j.at("color").get_to(s.color);
    j.at("init_velocity").get_to(s.init_velocity);
    j.at("vertices").get_to(s.vertices);
    j.at("angle_acc").get_to(s.angle_acc);
    j.at("collider_radius").get_to(s.radius);
    j.at("init_angle").get_to(s.init_angle);
    j.at("acc").get_to(s.acc);
    j.at("gun_config").get_to(s.gun_config);
}

void from_json(const json &j, GunConfig &g)
{
    j.at("bullets_radius").get_to(g.bullets_radius);
    j.at("bullets_vel").get_to(g.bullets_vel);
    j.at("bullets_ttl").get_to(g.bullets_ttl);
    j.at("cooldown").get_to(g.cooldown);
    j.at("bullets_color").get_to(g.bullets_color);
}