const Joi = require('@hapi/joi');
const models = require('./models');
//const { isSchema } = required('@hapi/joi');

const userSchema = Joi.object({
    name: Joi.string().min(2).max(20).required(),
    surname: Joi.string().min(2).max(20).required(),
    job: Joi.string().min(2).max(20).required(),
    age: Joi.number().integer().min(2).max(20).required(),
    imageUrl: Joi.string().required(),
    password: Joi.string().min(8).max(20).required(),
    email: Joi.string().min(12).max(25).required()
})

//
const value = userSchema.validate({
    name: 'Ashot',
    surname: 'Karapetyan',
    age: '32',
    job: 'oficer',
    imageurl: 'https://8.jpg',
    email: 'ashot32@gmail.com',
    password: 'some12!A'
});

// const validate = async () => {
//     try{
//         const value = await userSchema.validateAsync({ email: 'armgmail.com'});
//     }
//     catch (err) {
//         console.log(err)
//     }
// }
//validate()


//module.exsports.