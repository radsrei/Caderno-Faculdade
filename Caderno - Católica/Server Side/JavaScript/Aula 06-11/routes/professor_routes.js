import express from 'express'

const router = express.Router()

router.get('/professor', getProfessor)
router.post('/professor',createProfessor)
router.put('/professor/:matr', updateProfessor)
router.delete('/professor/:matr', deleteProfessor)

export default router