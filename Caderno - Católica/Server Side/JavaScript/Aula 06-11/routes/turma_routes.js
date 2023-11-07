import express from 'express'

const router = express.Router()

router.get('/turma', getTurma)
router.post('/turma',createTurma)
router.put('/turma/:id', updateTurma)
router.delete('/turma/:id', deleteTurma)

export default router